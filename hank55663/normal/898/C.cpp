#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
bool equal(string s1,string s2){
    for(int j=0;j<s1.size();j++){
        if(s1[j]!=s2[j])
            return false;
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    map<string,vector<string> > m;
    for(int i = 0;i<n;i++){
        string s1;
        int k;
        cin>>s1>>k;
        while(k--){
            string s2;
            cin>>s2;
            reverse(s2.begin(),s2.end());
            m[s1].pb(s2);
        }
    }
    printf("%d\n",m.size());
    for(auto it:m){
        sort(it.y.begin(),it.y.end());
        vector<string> ans;
        for(int j=0;j<it.y.size();j++){
            if(j==it.y.size()-1||!equal(it.y[j],it.y[j+1])){
                reverse(it.y[j].begin(),it.y[j].end());
                ans.pb(it.y[j]);
            }
        }
        cout<<it.x;
        printf(" %d",ans.size());
        sort(ans.begin(),ans.end());
        for(auto it:ans)
        cout<<" "<<it;
        printf("\n");
    }
}
/*
1 8 18
2 7 17
3 6 16
4 5 15
5 14
6 13
7 12
8 11
9 10
10 19
11 18
12 17
13 16
14 15
0 ~ 2345 2
2346 ~ 9999 1
 9999
12345
*/