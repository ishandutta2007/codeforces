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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
int f[2000005];
void KMP(vector<pair<LL,char> > c){
    f[0]=-1;
    int j=-1;
    for(int i = 1;i<c.size();i++){
        while(j!=-1&&c[i]!=c[j+1])j=f[j];
        if(c[i]==c[j+1])j++;
        f[i]=j;
    }
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<LL,char> > s,t;
    for(int i = 0;i<n;i++){
        int x;
        char a;
        scanf("%d-%c",&x,&a);
        if(s.size()&&s.back().y==a)s.back().x+=x;
        else s.pb(mp(x,a));
    }
    for(int i = 0;i<m;i++){
        int x;
        char a;
        scanf("%d-%c",&x,&a);
        if(t.size()&&t.back().y==a)t.back().x+=x;
        else t.pb(mp(x,a));
    }
    //for(auto it:s)printf("%d-%c ",it.x,it.y);
    //printf("\n");
   //  for(auto it:t)printf("%d-%c ",it.x,it.y);
    //printf("\n");
    if(t.size()==1){
        LL ans=0;
        for(auto it:s){
            if(it.y==t[0].y&&it.x>=t[0].x){
                ans+=it.x-t[0].x+1;
            }
        }
        printf("%lld\n",ans);
    }
    else if(t.size()==2){
        int ans=0;
        for(int i = 0;i<s.size()-1;i++){
            if(s[i].y==t[0].y&&s[i+1].y==t[1].y&&s[i].x>=t[0].x&&s[i+1].x>=t[1].x)ans++;
        }
        printf("%d\n",ans);
    }
    else{
        m=t.size();
        vector<pair<LL,char> > t2=t;
        t2.pop_back();
        reverse(t2.begin(),t2.end());
        t2.pop_back();
        reverse(t2.begin(),t2.end());
        KMP(t2);
        int j = -1;
        int ans=0;
        for(int i = 1;i<s.size()-1;i++){
            while(j!=-1&&s[i]!=t2[j+1])j=f[j];
            if(s[i]==t2[j+1])j++;
            if(j==t2.size()-1){
              //  printf("? %d %d\n",i+1,i+1-m+1);
                if(s[i+1].y==t.back().y&&s[i+1].x>=t.back().x&&i+1-t.size()+1>=0&&s[i+1-t.size()+1].y==t[0].y&&s[i+1-t.size()+1].x>=t[0].x)ans++;
                j=f[j];
            }
        }
        printf("%d\n",ans);
    }
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}