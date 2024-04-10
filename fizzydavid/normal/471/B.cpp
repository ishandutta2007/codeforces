//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,cnt[2011],a1[2011],a2[2011],a3[2011];
struct data
{
    int x,id;
    bool operator< (data t)const
    {
        return x<t.x;
    }
}a[2011];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i].x=x;a[i].id=i;
        cnt[x]++;
    }
    sort(a+1,a+1+n);
    int cnt1=0;
    bool ok=0;
    for(int i=1;i<=2000;i++)
    {
        if(cnt[i]==2)
        {
            cnt1++;
        }
        else if(cnt[i]>2)
        {
            ok=1;
            break;
        }
        if(cnt1>1){ok=1;break;}
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        a1[i]=a2[i]=a3[i]=a[i].id;
    }
    int tmp=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i].x]>2)
        {
            swap(a2[i],a2[i+1]);
            swap(a3[i+1],a3[i+2]);
            break;
        }
        else if(cnt[a[i].x]==2)
        {
            if(tmp)
            {
                swap(a3[i],a3[i+1]);
                break;
            }
            else
            {
                tmp=1;
                swap(a2[i],a2[i+1]);
                i++;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)cout<<a1[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++)cout<<a2[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++)cout<<a3[i]<<' ';cout<<endl;
    return 0;
}