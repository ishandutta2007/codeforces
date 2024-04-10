#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
pair<string,vector<string> > p[105];
string mes[105];
set<string> s;
set<string> can[105];
void solve(){
    s.clear();
    int n;
    scanf("%d", &n);
    for(int i =0;i<n;i++){
        string ss;
        cin>>ss;
        s.insert(ss);
    }
    int m;
    scanf("%d\n",&m);
    for(int i = 0;i<m;i++){
        can[i]=s;
        mes[i]="";
        string name;
        char c;
        while(scanf("%c",&c)&&c!=':'){
            name+=c;
        }
        string str;
        vector<string> v;
        while(scanf("%c",&c)&&c!='\n'){
            mes[i]+=c;
            if(c>='a'&&c<='z'){
                str+=c;
            }
            else if(c>='A'&&c<='Z'){
                str+=c;
            }
            else if(c>='0'&&c<='9'){
                str+=c;
            }
            else{
                v.pb(str);
                if(can[i].find(str)!=can[i].end())
                can[i].erase(str);
                str="";
            }
        }
        v.pb(str);
        if(can[i].find(str)!=can[i].end())
            can[i].erase(str);
        p[i]=mp(name,v);
    }
    queue<int> q;
    int inq[1005];
    MEM(inq);
    for(int i = 0;i<m;i++){
        if(i!=0){
            if(can[i].find(p[i-1].x)!=can[i].end()){
                can[i].erase(p[i-1].x);
            }
        }
        if(i!=m-1){
            if(can[i].find(p[i+1].x)!=can[i].end()){
                can[i].erase(p[i+1].x);
            }
        }
        if(can[i].size()<=1&&p[i].x=="?"){
            q.push(i);
            inq[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(can[x].size()==0){
            printf("Impossible\n");
            return ;
        }   
        p[x].x=*can[x].begin();
        if(x!=0){
            if(can[x-1].find(p[x].x)!=can[x-1].end())
                can[x-1].erase(p[x].x);
            if(can[x-1].size()==1&&p[x-1].x=="?"&&!inq[x-1])
                q.push(x-1),inq[x-1]=1;
        }
        if(x!=m-1){
            if(can[x+1].find(p[x].x)!=can[x+1].end())
                can[x+1].erase(p[x].x);
            if(can[x+1].size()==1&&p[x+1].x=="?"&&!inq[x+1])
                q.push(x+1),inq[x+1]=1;
        }
    } 
    for(int i = 0;i<m;i++){
        if(p[i].x=="?"){
            p[i].x=*can[i].begin();
            if(i!=m-1){
                if(can[i+1].find(p[i].x)!=can[i+1].end())
                    can[i+1].erase(p[i].x);
            }
        }
        printf("%s:%s\n",p[i].x.c_str(),mes[i].c_str());
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
1 
2 6 
3 5 
4
*/