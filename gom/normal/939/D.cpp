#include <bits/stdc++.h>
#define N 100005
using namespace std;
vector<int>g[N];
string s1,s2;
int n,ans,t,c[30],k,edge[N][2];
bool visit[30],done[30];
bool gg[30][30];
int res[N][2],dd;
void dfs(int curr,int par)
{
    if(curr!=par){
        res[dd][0]=par,res[dd][1]=curr;
        dd++;
    }
    t++;
    visit[curr]=true;
    for(auto &it : g[curr]){
        if(!visit[it])
            dfs(it,curr);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s1>>s2;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i])
            continue;
        if(gg[s1[i]-'a'][s2[i]-'a'])
            continue;
        edge[k][0]=s1[i]-'a';
        edge[k++][1]=s2[i]-'a';
        gg[s1[i]-'a'][s2[i]-'a']=true;
        gg[s2[i]-'a'][s1[i]-'a']=true;
        g[s1[i]-'a'].push_back(s2[i]-'a');
        g[s2[i]-'a'].push_back(s1[i]-'a');
    }
    for(int i=0;i<26;i++){
        t=0;
        if(!visit[i]){
            dfs(i,i);
            ans+=t-1;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<(char)(res[i][0]+'a')<<" "<<(char)(res[i][1]+'a')<<endl;
    }
    return 0;
}