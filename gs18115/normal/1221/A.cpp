#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        vector<int>v;
        int n,i,j;
        cin>>n;
        for(i=0;i<n;i++)
        {
            int s;
            cin>>s;
            if(s<=2048)
                v.eb(s);
        }
        n=v.size();
        for(i=1;i<2048;i*=2)
        {
            int c=0;
            for(j=0;j<n;j++)
                if(v[j]==i)
                    c++;
            c/=2;
            for(j=0;j<n;j++)
                if(v[j]==i&&c>0)
                    v[j]=i*2,c--;
        }
        for(i=0;i<n;i++)
            if(v[i]==2048)
                break;
        if(i<n)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    cout<<endl;
    return 0;
}