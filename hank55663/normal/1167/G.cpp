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
double myatan(int x,int y){
    if(y==0)
    return pi/2;
    return atan((double)x/y);
}
int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[200005];
    set<int> s;
    unordered_set<int> s2;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        s.insert(a[i]);
        s2.insert(a[i]);
    }
    int q;
    scanf("%d",&q);
    map<int,double> m;
    while(q--){
        int x;
        scanf("%d",&x);
        /*if(m.find(x)!=m.end()){
            printf("%.12lf\n",m[x]);
            continue;
        }*/
        auto it=s.lower_bound(x);
        auto it2=it;
        int dis=1e9;
        if(it==s.begin()){
            dis=*it-x;
        }
        else if(it==s.end()){
            it2--;
            dis=x-*it2-1;
        }
        else{
            it2--;
            dis=min(*it-x,x-*it2-1);
        }
        double ans;
        ans = myatan(1.0,dis);
        while(it!=s.end()){
            if((*it-x)>dis*2+10)
            break;
            if(x-*it2>dis*2+10)
            break;
            if(x-(*it-x)-1==*it2){
                ans = max(ans,myatan(1.0,(*it-x))*2);
                break;
            }
            if(*it-x!=0)
            if(x-(*it-x)==*it2){
                ans =  max(ans,myatan(1.0,(*it-x))*2);
                break;
            }
            if(x-(*it-x)-2==*it2){
                ans =  max(ans,myatan(1.0,(*it-x+1))*2);
                break;
            }
            if(*it-x<x-*it2){
                it++;
            }
            else{
                if(it2==s.begin())
                break;
                it2--;
            }
        }
        printf("%.12lf\n",ans);
        //m[x]=ans;
    }
}