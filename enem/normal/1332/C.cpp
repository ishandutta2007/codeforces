#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = a; i <= b; i++)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    int n,k,j;
    cin>>n>>k;
    cin>>s;
    int ans=0;
    int maxch[26];
    
    rep(i,0,(k-1)/2)
    {
        rep(y,0,25)
            maxch[y]=0;
        j=k-i-1;
        if(i!=j){
            rep(x,0,n/k-1)
            {
                maxch[s[i+k*x]-'a']++;
                maxch[s[j+k*x]-'a']++;
            }
            ans=ans+2*n/k- *max_element(maxch,maxch+26);
        }
        else{
            rep(x,0,n/k-1)
            {
                maxch[s[i+k*x]-'a']++;
            }
            ans=ans+n/k- *max_element(maxch,maxch+26);
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}