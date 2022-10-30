#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
string name[2000];
bool ok[2000][2000];
int last[2000][2000];
int prev[2000][2000];
map<string,int> m;
pair<pair<int,int>,int> c[1000];
char str[32];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int now=0;
    for(int i=0;i<a;i++){
        scanf("%s",str);
        string P=str;
        scanf("%s",str);
        string Q=str;
        int d;
        scanf("%d",&d);
        int p,q;
        if(m.count(P)){
            p=m[P];
        }else{
            p=now;
            name[now]=P;
            m[P]=now++;
        }
        if(m.count(Q)){
            q=m[Q];
        }else{
            q=now;
            name[now]=Q;
            m[Q]=now++;
        }
        c[i]=make_pair(make_pair(p,q),d);
    }
    for(int i=0;i<now;i++)
        for(int j=0;j<now;j++)
            last[i][j]=prev[i][j]=-99999999;
    for(int i=0;i<a;i++){
        if(0<c[i].second-last[c[i].first.second][c[i].first.first]&&c[i].second-last[c[i].first.second][c[i].first.first]<=b){
            ok[c[i].first.first][c[i].first.second]=true;
            ok[c[i].first.second][c[i].first.first]=true;
        }else if(0<c[i].second-prev[c[i].first.second][c[i].first.first]&&c[i].second-prev[c[i].first.second][c[i].first.first]<=b){
            ok[c[i].first.first][c[i].first.second]=true;
            ok[c[i].first.second][c[i].first.first]=true;
        }
        if(last[c[i].first.first][c[i].first.second]!=c[i].second)prev[c[i].first.first][c[i].first.second]=last[c[i].first.first][c[i].first.second];
        last[c[i].first.first][c[i].first.second]=c[i].second;
    }
    int ret=0;
    for(int i=0;i<now;i++)
        for(int j=i+1;j<now;j++)
            if(ok[i][j])ret++;
    printf("%d\n",ret);
    for(int i=0;i<now;i++)
        for(int j=i+1;j<now;j++)
            if(ok[i][j])printf("%s %s\n",name[i].c_str(),name[j].c_str());
}