#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int>a[234567];
int n[234567],s[234567];
pair<int,int>X[234567];
int i,j,b,c,T;
map<int,int>m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>n[i];
        for(j=0;j<n[i];j++)
        {
            cin>>b;
            a[i].push_back(b);
            s[i]+=b;
        }
        for(j=0;j<n[i];j++)
        {
            if(m[s[i]-a[i][j]]!=0)
            {
                if(X[m[s[i]-a[i][j]]].first!=i+1)
                {
                    cout<<"YES\n";
                    cout<<X[m[s[i]-a[i][j]]].first<<' '<<X[m[s[i]-a[i][j]]].second<<'\n';
                    cout<<i+1<<' '<<j+1;
                    return 0;
                }
            }
            else
            {
                c++;
                m[s[i]-a[i][j]]=c;
                X[c].first=i+1;
                X[c].second=j+1;
            }
        }
    }
    cout<<"NO";
    return 0;
}