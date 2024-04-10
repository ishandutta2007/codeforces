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
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
//#define next Next
#define index Index
map<int,int> m[100005];
int tmp[100005];
int main(){
    int L,n,p,t;
    scanf("%d %d %d %d",&L,&n,&p,&t);
    vector<int> v;
    int last=0;
    int be=0;
    int l[100005],r[100005];
    for(int i=0;i<n;i++){
        //int l,r;
        scanf("%d %d",&l[i],&r[i]);
    }
    last = 0;
    int ans=0;
    for(int i = 0;i<n;i++){
        last=max(last,tmp[i]);
        if(m[i].find(0)!=m[i].end())
            last=max(last,m[i][0]);
        int len=r[i]-l[i];
        ans=max(ans,len/p+last);
        int target=l[i]+len/p*p+t;
        int j=upper_bound(l,l+n,target)-l-1;
        tmp[j+1]=max(tmp[j+1],len/p+last);
        if(j!=i){
            int mnum=(target-l[j])%p;
            m[j][mnum]=max(m[j][mnum],len/p+last-(target-l[j])/p);
            auto it=m[j].find(mnum);
            if(it==m[j].begin());
            else{
                it=prev(it);
                if(it->y>=m[j][mnum]){
                    m[j].erase(mnum);
                }
            }
            it=m[j].find(mnum);
            if(it!=m[j].end()){
                it=next(it);
                while(it!=m[j].end()){
                    auto it2=next(it);
                    if(it->y<=m[j][mnum]){
                        m[j].erase(it);
                        it=it2;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        for(auto it:m[i]){
            if(it.y>last){
                int len=r[i]-l[i]-it.x;
                ans=max(ans,len/p+it.y);
                int target=l[i]+len/p*p+t+it.x;
                int j=upper_bound(l,l+n,target)-l-1;
                tmp[j+1]=max(tmp[j+1],len/p+it.y);
                if(j!=i){
                    int mnum=(target-l[j])%p;
                    m[j][mnum]=max(m[j][mnum],len/p+it.y-(target-l[j])/p);
                    auto it=m[j].find(mnum);
                    if(it==m[j].begin());
                    else{
                        it=prev(it);
                        if(it->y>=m[j][mnum]){
                            m[j].erase(mnum);
                        }
                    }
                    it=m[j].find(mnum);
                    if(it!=m[j].end()){
                        it=next(it);
                        while(it!=m[j].end()){
                            auto it2=next(it);
                            if(it->y<=m[j][mnum]){
                                m[j].erase(it);
                                it=it2;
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */