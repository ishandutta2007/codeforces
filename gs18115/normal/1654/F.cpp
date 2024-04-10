#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0;i<1<<n;i++)
        v.eb(i);
    sort(all(v),[&](int i,int j){return s[i]<s[j];});
    vector<int>num(1<<n);
    for(int i=0,j=0;i<1<<n;i++)
    {
        if(i!=0&&s[v[i]]!=s[v[i-1]])
            j++;
        num[v[i]]=j;
    }
    for(int it=0;it<n;it++)
    {
        const int ci=1<<it;
        auto num2=num;
        sort(all(v),[&](int i,int j){
            if(num2[i]==num2[j])
                return num2[ci^i]<num2[ci^j];
            return num2[i]<num2[j];
        });
        for(int i=0,j=0;i<1<<n;i++)
        {
            if(i!=0&&(num2[v[i]]!=num2[v[i-1]]||num2[ci^v[i]]!=num2[ci^v[i-1]]))
                j++;
            num[v[i]]=j;
        }
    }
    for(int i=0;i<1<<n;i++)
        cout<<s[i^v[0]];
    cout<<endl;
    return 0;
}