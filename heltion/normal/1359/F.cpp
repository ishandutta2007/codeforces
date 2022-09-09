#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 25000;
int x[maxn], y[maxn];
double dx[maxn], dy[maxn];
constexpr double eps = 1e-9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0, s; i < N; i += 1){
        cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s;
        double d = s / hypot(dx[i], dy[i]);
        dx[i] *= d;
        dy[i] *= d;
    }
    double ans = 1e10;
    for(int i = 0; i < N; i += 1)
        for(int j = i + 1; j < N; j += 1){
            double fm = dx[i] * dy[j] - dy[i] * dx[j];
            if(abs(fm) < eps){
                if(abs((x[i] - x[j]) * dy[i] - (y[i] - y[j]) * dx[i]) < eps){
                    if(dx[i] * dx[j] < 0){
                        double t = (x[i] - x[j]) / (dx[j] - dx[i]);
                        if(t > 0) ans = min(ans, t);
                    }
                    else{
                        {
                            double t = (x[i] - x[j]) / dx[j];
                            if(t > 0) ans = min(ans, t);
                        }
                        {
                            double t = (x[j] - x[i]) / dx[i];
                            if(t > 0) ans = min(ans, t);
                        }
                    }
                }
            }
            else{
                double ti = (x[j] * dy[j] - y[j] * dx[j] - x[i] * dy[j] + y[i] * dx[j]) / fm;
                double tj = (x[i] + dx[i] * ti - x[j]) / dx[j];
                if(ti > -eps and tj > -eps) ans = min(ans, max(ti, tj));
            }
        }
    if(ans < 1e10 - 1)
        cout << fixed << setprecision(20) << ans << "\n";
    else cout << "No show :(\n";
    return 0;
}