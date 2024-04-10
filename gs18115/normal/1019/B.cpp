#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
const int INF=1e9+10;
int N;
int s,e,mid;
int n[MAXN];
bool flag;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    if((N>>1)&1)
        return cout<<"! "<<-1<<endl,0;
    fill(n,n+MAXN,-1);
    cout<<"? "<<1<<endl;
    cin>>n[0];
    cout<<"? "<<1+(N>>1)<<endl;
    cin>>n[N>>1];
    if(n[0]==n[N>>1])
        return cout<<"! "<<1<<endl,0;
    else if(n[0]<n[N>>1])
        flag=true;
    else
        flag=false;
    s=0;
    e=N>>1;
    while(s<=e)
    {
        mid=s+e>>1;
        cout<<"? "<<1+mid<<endl;
        cin>>n[mid];
        cout<<"? "<<1+mid+(N>>1)<<endl;
        cin>>n[mid+(N>>1)];
        if(n[mid]==n[mid+(N>>1)])
            return cout<<"! "<<1+mid,0;
        else if(n[mid]<n[mid+(N>>1)]^flag)
            e=mid-1;
        else
            s=mid+1;
    }
    return 0;
}