#include<bits/stdc++.h>
#define maxn 234000
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,m,k,a[maxn],r,p,q;
char s[maxn];

int main()
{
    scanf("%d%d%d",&n,&p,&q); k=0;
    scanf("%s",s); r=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='*') r=0;
        else {
            if (r==0){
                if (p>q) p--,r=1,k++;
                else if (p<q) q--,r=-1,k++;
                else if (p) p--,r=1,k++;
            }
            else if (r==1){
                if (q) q--,r=-1,k++; else r=0;
            }
            else if (r==-1){
                if (p) p--,r=1,k++; else r=0;
            }
        }
    }
    cout << k << endl;
}