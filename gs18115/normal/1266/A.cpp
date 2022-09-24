#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        string s;
        cin>>s;
        int S=0;
        int zc=0;
        int tc=0;
        for(int i=0;i<s.size();i++)
        {
            int x=s[i]-'0';
            S+=x;
            if(x==0)
                zc++;
            if(x%2==0)
                tc++;
        }
        if(tc>1&&zc>0&&S%3==0)
            cout<<"red\n";
        else if(zc==s.size())
            cout<<"red\n";
        else
            cout<<"cyan\n";
    }
    cout<<endl;
    return 0;
}