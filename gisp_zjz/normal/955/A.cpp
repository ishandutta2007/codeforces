#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll hh,mm,h,d,c,n;
double ans;

int main()
{
    cin >> hh >> mm >> h >> d >> c >> n;
    mm+=hh*60;
    if (h==0) {cout << 0 << endl;return 0;}

    if (mm<1200) ans=min(1.0*((h-1)/n+1)*c,0.8*((h+(1200-mm)*d-1)/n+1)*c);
    else ans=0.8*((h-1)/n+1)*c;
    printf("%.4f\n",ans);
}