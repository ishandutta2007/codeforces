#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
pair<string,int> str[1000005];
bool cmp(const pair<string,int> &p,const pair<string,int> &q){
    for(int i = 0;i<p.x.size();i++){
        if(p.x[i]!=q.x[i]){
            if(i%2==0)return p.x[i]<q.x[i];
            else return p.x[i]>q.x[i];
        }
    }
    return false;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i =0;i<n;i++){
        char c[1000005];
        scanf("%s",c);
        str[i]=mp(string(c),i);
    }
    sort(str,str+n,cmp);
    for(int i=0;i<n;i++)printf("%d ",str[i].y+1);
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/