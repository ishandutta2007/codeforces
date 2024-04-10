
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> set_t;
set_t p,s,r;
int query(){
    int ret=0;
    if(s.empty()){
        ret+=p.size();
    }
    else{
        if(r.empty());
        else{
            int L=min(*r.find_by_order(r.size()-1),*s.find_by_order(0));
            pii mid=mp(*r.find_by_order(0),*r.find_by_order(r.size()-1));
            int R=max(*r.find_by_order(0),*s.find_by_order(s.size()-1));
            mid=mp(max(mid.x,L),min(mid.y,R));
            if(L>=R){
                ret+=p.size();
            }
            else{
                ret+=p.order_of_key(L)+p.order_of_key(mid.y)-p.order_of_key(mid.x)+p.size()-p.order_of_key(R);
            }
        }
    }
  //  printf("%d ",ret);
    if(r.empty()){
        ret+=s.size();
        //printf("? %d\n",s.size());
    }
    else{
        if(p.empty());//||s.empty());
        else{
            int L=min(*p.find_by_order(p.size()-1),*r.find_by_order(0));
            pii mid=mp(*p.find_by_order(0),*p.find_by_order(p.size()-1));
            int R=max(*p.find_by_order(0),*r.find_by_order(r.size()-1));
            mid=mp(max(mid.x,L),min(mid.y,R));
            if(L>=R){
                ret+=s.size();
            }
            else{
                ret+=s.order_of_key(L)+s.order_of_key(mid.y)-s.order_of_key(mid.x)+s.size()-s.order_of_key(R);
            }
        }
    }
  //  printf("%d ",ret);
    if(p.empty()){
        ret+=r.size();
    }
    else{
        if(s.empty());//||r.empty());
        else{
            int L=min(*s.find_by_order(s.size()-1),*p.find_by_order(0));
            pii mid=mp(*s.find_by_order(0),*s.find_by_order(s.size()-1));
            int R=max(*s.find_by_order(0),*p.find_by_order(p.size()-1));
            mid=mp(max(mid.x,L),min(mid.y,R));
            if(L>=R){
                ret+=r.size();
            }
            else{
                ret+=r.order_of_key(L)+r.order_of_key(mid.y)-r.order_of_key(mid.x)+r.size()-r.order_of_key(R);
            }
        }
    }
    return ret;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[200005];
    scanf("%s",c);
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='R')
        r.insert(i);
        else if(c[i]=='S')
        s.insert(i);
        else
        p.insert(i);
    }
    printf("%d\n",query());
    while(q--){
        int x;
        char cc;
        scanf("%d %c",&x,&cc);
        x--;
        if(c[x]=='R')
        r.erase(x);
        if(c[x]=='S')
        s.erase(x);
        if(c[x]=='P')
        p.erase(x);
        c[x]=cc;
        if(c[x]=='R')
        r.insert(x);
        if(c[x]=='S')
        s.insert(x);
        if(c[x]=='P')
        p.insert(x);
        printf("%d\n",query());
    }
}