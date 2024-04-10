#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


queue <int> Q0, Q1, Q2;

int n, n1, n2, n3, t1, t2, t3;

int main(){
    scanf("%d%d%d%d%d%d%d", &n, &n1, &n2, &n3, &t1, &t2, &t3);
    for (int i = 1; i <= n1; i++){
        if (n){
            n--;
            Q0.push(t1);
        }else break;
    }
    int ans = 0, o1 = 0, o2 = 0, o3 = 0;
    while (!Q0.empty() || !Q1.empty() || !Q2.empty()){
        //cout << Q0.size() << " " << Q1.size() << " " << Q2.size() << endl;
        int p1, p2, p3;
        if (!Q2.empty()) p3 = Q2.front(); else p3 = INF;
        if (!Q1.empty() && Q2.size() < n3) p2 = Q1.front(); else p2 = INF;
        if (!Q0.empty() && Q1.size() < n2) p1 = Q0.front(); else p1 = INF;
        if (p1 <= p2 && p1 <= p3){
            Q1.push(max(o2, p1) + t2); Q0.pop(); o1 = max(o1, max(o2, p1));
            if (n){
                Q0.push(max(o1, p1) + t1);
                n--;
            }
        }else if (p2 <= p1 && p2 <= p3){
            Q2.push(max(o3, p2) + t3); Q1.pop(); o2 = max(o2, max(o3, p2));
        }else if (p3 <= p1 && p3 <= p2){
            ans = p3; Q2.pop(); o3 = p3;
        }
    }
    cout << ans << endl;

}