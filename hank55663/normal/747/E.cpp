#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
int main(){
    int level=0;
    vector<vector<string> > ans;
    vector<int> stk;
    char c;
    while(true){
        while(!stk.empty()&&stk.back()==0){
            level--;
            stk.pop_back();
        }
        string name;
        while(scanf("%c",&c)&&c!=','){
            name+=c;
        }
        int sum=0;
        int end=1;
        while(scanf("%c",&c)!=EOF){
            if(c==','){
                end=0;
                break;
            }
            if(c=='\n'){
                break;
            }
            sum=sum*10+c-'0';
        }
        if(ans.size()==level)
        ans.pb(vector<string>());
        //cout<<level<<" "<<name<<endl;
        ans[level].pb(name);
        if(end)
        break;
        if(stk.size()){
            stk.back()--;
        }
        stk.pb(sum);
        level++;
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        for(auto it2:it){
            printf("%s ",it2.c_str());
        }
        printf("\n");
    }
}