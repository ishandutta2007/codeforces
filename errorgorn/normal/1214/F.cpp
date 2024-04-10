#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int m,n;
vector<ii> house;
vector<ii> people;
int ans[200005];
long long dist(int i){
    long long ans=0;
    int dist;
    int iter_p=0,iter_h=i;
    for (int x=0;x<n;x++){
        dist=abs(house[iter_h].first-people[iter_p].first);
        ans+=min(dist,m-dist);
        iter_p++;
        iter_h=(iter_h+1)%n;
    }
    return ans;
}
int ternary_search(int i,int j){
    int a=i,b=j,c1,c2,d;
    long long v1,v2;
    while (a!=b){
        if (b-a==1){
            if (dist(a)>dist(b)) a=b;
            else b=a;
        }
        else if (b-a==2){
            long long va=dist(a),vb=dist(b);
            c1=(a+b)>>1;
            v1=dist(c1);
            if (v1<=va && v1<=vb){
                a=c1;
                b=c1;
            }
            else if (va<=v1 && va<=vb){
                b=a;
            }
            else{
                a=b;
            }
        }
        else{
            d=(b-a)/3;
            c1=a+d;
            c2=c1+d;
            v1=dist(c1);
            v2=dist(c2);
            if (v1<v2) b=c2;
            else a=c1;
        }
    }
    return a;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    int t;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        house.push_back(ii(t,x));
    }
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        people.push_back(ii(t,x));
    }
    sort(house.begin(),house.end());
    sort(people.begin(),people.end());

    /*long long pp=1000000000000000000;
    for (int x=0;x<n;x++){
        printf("%d %lld\n",x,dist(x));
        pp=min(pp,dist(x));
    }
    printf("\n");
    printf("%lld\n",pp);*/
    int opt,opt1,opt2;
    if (n==1) opt=0;
    else{
        opt1=ternary_search(0,(n>>1));
        opt2=ternary_search((n>>1)+1,n-1);
        if (dist(opt1)<dist(opt2)) opt=opt1;
        else opt=opt2;
    }
    printf("%lld\n",dist(opt));
    int iter=0;
    for (int x=0;x<n;x++){
        ans[house[opt].second]=people[iter].second;
        iter++;
        opt=(opt+1)%n;
    }
    for (int x=0;x<n;x++){
        printf("%d ",ans[x]+1);
    }
}