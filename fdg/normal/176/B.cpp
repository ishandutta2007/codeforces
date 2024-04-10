#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
//#include <omp.h>

#define ll long long

using namespace std;

char s1[1001],s2[1001];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int k,f0=1,f1=0,mod=1000000007;
    cin >> s1 >> s2 >> k;
    int l=strlen(s1);
    for(int i=1;i<=k;++i) {
        int n0=(1LL*f1*(l-1))%mod,n1=(f0+1LL*f1*(l-2))%mod;
        f0=n0; f1=n1;
//      cout << f0 << " " << f1 << endl;
    }
    int ans=0;
    for(int i=0;i<l;++i) {
        bool ok=true;
        for(int j=0;j<l;++j) {
            if (s1[j]!=s2[(i+j)%l]) {
                ok=false;
                break;
            }
        }
        if (ok) {
            if (i==0) ans=(ans+f0)%mod;
            else ans=(ans+f1)%mod;
        }
    }
    cout << ans << endl;
    return 0;
}