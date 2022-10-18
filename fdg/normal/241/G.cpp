#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>

using namespace std;

double x[505],p[505]; int s[505];
double r[505];

void relax(int i,int j) {
    int t=s[j];
    r[i]=min(r[i],1.0*(x[i]-x[t])*(x[i]-x[t])/4.0/r[t]);
}

double solve(int n) {
    memset(r,0,sizeof(r));
    memset(s,0,sizeof(s));
    int ss=0;
    double sum=0;
    for(int i=0;i<n;++i) {
        r[i]=p[i];
        for(int j=0;j<min(300,ss);++j)
            relax(i,ss-1-j);
        while(ss&&r[s[ss-1]]<=r[i])
            --ss;
        s[ss++]=i;
        cout << ss << endl;
        sum+=r[i];
//      cout << r[i] << endl;
    }
    return sum;
}

double dist(int i,int j) {
    return sqrt(0.0+1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(r[i]-r[j])*(r[i]-r[j]));
}

double my(int n) {
    double ans=0;
    memset(r,0,sizeof(r));
    for(int i=0;i<n;++i) {
        double ll=0,rr=p[i];
        for(int it=0;it<70;++it) {
            double m=(ll+rr)/2;
            bool ok=true;
            for(int j=0;j<i;++j) {
                r[i]=m;
                if (dist(i,j)+1e-6<r[i]+r[j]) ok=false;
            }
            if (ok) ll=m;
            else rr=m;
        }
        r[i]=rr;
//      cout << rr << endl;
        ans+=r[i];
    }
    return ans;
}

int Rand() {
    return rand()*RAND_MAX+rand();
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
/*  cin >> n;
    for(int i=0;i<n;++i)
        cin >> x[i] >> p[i];
    cout << solve(n) << endl;
    cout << my(n) << endl;
    n=20;
    for(int t=0;t<n;++t) {
        x[t]=(t ? x[t-1] : 0) + rand()%100+1,p[t]=rand()+1;
    }
    sort(x,x+n);
    cout << solve(n) << endl;
    cout << my(n) << endl;*/
/*  cout << n << endl;
    for(int i=0;i<n;++i)
        cout << "cout << \"" << x[i] << " " << p[i] << "\" << endl;" << endl;*/
    srand(time(NULL));
    n=500;
    x[0]=0; p[0]=1000000;
    int d=500,last=0;
    for(int i=1;i<n;++i) {
        x[i]=last+d; last=x[i];
        p[i]=d; --d;
    }
    x[n-1]=1000000;
    p[n-1]=1000000;
    cout << n << endl;
    for(int i=0;i<n;++i)
        cout << (int)x[i] << " " << (int)p[i] << endl;
//  cout << solve(n) << endl;
//  cout << my(n) << endl;
/*  int test=0;
    while(true) {
        n=500;
//  cout << n << endl;
        int last=0,last2=1000000;
        for(int i=0;i<n;++i) {
            last=last+Rand()%2000+1;
            x[i]=last; p[i]=last2-Rand()%1-1;
//          cout << x[i] << " " << p[i] << endl;
        }
        cout << test << endl; ++test;
        if (fabs(solve(n)-my(n))>1) {
            cout << "fail\n";
            break;
        }
    }*/
//  cout << solve(n) << endl;
//  cout << my(n) << endl;
    return 0;
}