#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<ctime>
#include<bitset>
#define LL long long
#define db double
#define EPS 1e-15
#define inf 1e10

using namespace std;

double X1, Y1, X2, Y2;  
double vx, vy;  
double wx, wy;  
double v, t; 
double sqr(double x) {  
    return x * x;  
}  
double dis(double X1, double Y1, double X2, double Y2) {  
    return sqr(X1 - X2) + sqr(Y1 - Y2);  
}  
bool ok(double x) {  
    double tmpx, tmpy;  
    if(x > t) {  
        tmpx = X1 + vx * t + wx * (x - t);  
        tmpy = Y1 + vy * t + wy * (x - t);  
    } else {  
        tmpx = X1 + vx * x;  
        tmpy = Y1 + vy * x;  
    }  
    double d = dis(tmpx, tmpy, X2, Y2);  
    if(d < sqr(v * x)) return true;  
    return false;  
} 
int main(){
    cin>>X1>>Y1>>X2>>Y2;
    cin>>v>>t;
    cin>>vx>>vy;
    cin>>wx>>wy;
    double L = 0, R = 1e30;  
    int bi_cnt = 0;  
    while(bi_cnt < 1e6) {  
        double mid = (L + R) / 2;  
        if(ok(mid)) R = mid;  
        else L = mid;  
        ++bi_cnt;  
    }  
    printf("%.12f\n", R);  
    return 0;  
}