#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
long long L[210000];
long long R[210000];
long long c[210000];
int ret[210000];
pair<long long,int> z[210000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    long long ll,lr;
    for(int i=0;i<a;i++){
        long long p,q;
        scanf("%I64d%I64d",&p,&q);
        if(i){
            L[i-1]=p-lr;
            R[i-1]=q-ll;
            z[i-1]=make_pair(R[i-1],i-1);
        }
        ll=p;
        lr=q;
    }
    a--;
    std::sort(z,z+a);
    for(int i=0;i<b;i++)scanf("%I64d",c+i);
    bool ok=true;
    set<pair<long long,int> > S;
    for(int i=0;i<b;i++)S.insert(make_pair(c[i],i));
    S.insert(make_pair(1000000000000000001LL,0));
    for(int i=0;i<a;i++){
        long long left=L[z[i].second];
        long long right=R[z[i].second];
        pair<long long,int> val=*(S.lower_bound(make_pair(left,0)));
        if(val.first>right){
            ok=false;break;
        }
        ret[z[i].second]=val.second;
        S.erase(val);
    }
    if(!ok)printf("No\n");
    else{
        printf("Yes\n");
        for(int i=0;i<a;i++){
            if(i)printf(" ");
            printf("%d",ret[i]+1);
        }
        printf("\n");
    }
}