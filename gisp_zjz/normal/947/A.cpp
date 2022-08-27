#include<bits/stdc++.h>
#define maxn 2400300
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,ans,cnt;

void solve(int x,int y)
{
    int j=2,tmp=x;
    while (j*j<=tmp)
    {
        if (tmp%j==0){
            if (y==1) ans=min(ans,max(x-j+1,j+1));
            else{
                for (int i=0;i<j;i++) if (x-i>j) solve(x-i,y-1);
            }
            while (tmp%j==0) tmp/=j;
        }
        j++;
    }
    if (tmp>1){
        if (y==1) ans=min(ans,max(x-tmp+1,tmp+1));
        else {
            for (int i=0;i<tmp;i++) if (x-i>tmp) solve(x-i,y-1);
        }
    }
    //for (int i=0;i<r;i++) if (x-i>r) solve(x-i,y-1);
}

int main()
{
    scanf("%d",&n); ans=n;
    solve(n,2);
    cout << ans << endl;
}