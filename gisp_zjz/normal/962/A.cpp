#include<bits/stdc++.h>
#define maxn 234000
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,m,k,a[maxn],r;

int main()
{
    scanf("%d",&n); k=0;m=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]); k+=a[i];
    }
    for (int i=1;i<=n;i++)
    {
        m+=a[i];
        if (m*2>=k) {cout << i << endl;return 0;}
    }
}