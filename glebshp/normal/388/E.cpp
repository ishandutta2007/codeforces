#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define _abs(x) ((x)>0?(x):-(x))
#define eps 1.0E-6
#define PI acos(-1.0)

int N;
int t1[1010],x11[1010],y11[1010],t2[1010],x22[1010],y22[1010];
double x00[1010],y00[1010],vx[1010],vy[1010];
bool meet[1010][1010];
double t[1010][1010];

int most_freq(vector <double> &v){
    int N = v.size();
    int i,j,ans=0;
    sort(v.begin(),v.end());
    
    i = 0;
    while(i < N){
        for(j=i;j<N;j++) if(v[j] - v[i] > eps) break;
        ans = max(ans, j-i);
        i = j;
    }
    
    return ans;
}

int most_freq(vector <pair <double, double> > &v){
    int N = v.size();
    int i,j,k,ans=0;
    sort(v.begin(),v.end());
    
    i = 0;
    while(i < N){
        for(j=i;j<N;j++) if(v[j].first - v[i].first > eps) break;
        
        int tmp = 0;
        vector <double> w;
        for(k=i;k<j;k++) w.push_back(v[k].second);
        sort(w.begin(),w.end());
        REP(k,j-i) if(k == 0 || w[k] - w[k-1] > eps) tmp++;
        
        ans = max(ans, tmp);
        i = j;
    }
    
    return ans;
}

int main(void){
    int i,j;
    
    cin >> N;
    REP(i,N) cin >> t1[i] >> x11[i] >> y11[i] >> t2[i] >> x22[i] >> y22[i];
    
    REP(i,N){
        vx[i] = (double)(x22[i] - x11[i]) / (t2[i] - t1[i]);
        vy[i] = (double)(y22[i] - y11[i]) / (t2[i] - t1[i]);
        x00[i] = x11[i] - vx[i] * t1[i];
        y00[i] = y11[i] - vy[i] * t1[i];
    }
    
    REP(i,N) REP(j,i){
        // point i and point j meet at time t
        double T = 0.0;
        if(_abs(vx[i] - vx[j]) > eps) T = (x00[i] - x00[j]) / (vx[j] - vx[i]);
        if(_abs(vy[i] - vy[j]) > eps) T = (y00[i] - y00[j]) / (vy[j] - vy[i]);
        if(_abs(x00[i] + vx[i] * T - x00[j] - vx[j] * T) < eps && _abs(y00[i] + vy[i] * T - y00[j] - vy[j] * T) < eps){
            meet[i][j] = meet[j][i] = true;
            t[i][j] = t[j][i] = T;
        }
    }
    
    int ans = 1;
    
    REP(i,N){
        vector <double> times;
        REP(j,i) if(meet[i][j]) times.push_back(t[i][j]);
        int tmp = most_freq(times);
        ans = max(ans, tmp + 1);
        
        vector <pair <double, double> > v;
        REP(j,i) if(meet[i][j]){
            double dx = vx[j] - vx[i], dy = vy[j] - vy[i];
            double arg = atan2(dy, dx);
            while(arg < 4.0) arg += PI;
            double speed = cos(arg) * dx + sin(arg) * dy;
            v.push_back(make_pair(arg, speed));
        }
        tmp = most_freq(v);
        ans = max(ans, tmp + 1);
    }
    
    cout << ans << endl;
    
    return 0;
}