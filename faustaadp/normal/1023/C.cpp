#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,kos[202020];
char a[202020];
stack<ll> st;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    m=n-m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        if(a[i]=='(')
        {
            st.push(i);
        }
        else
        {
            if(m)
            {
                m-=2;
                kos[st.top()]=1;
                kos[i]=1;
            }
            st.pop();
        }
    }
    for(i=1;i<=n;i++)
        if(!kos[i])
            cout<<a[i];
    cout<<"\n";
}