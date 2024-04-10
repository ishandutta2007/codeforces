#include <cstdio>
#include <queue>
#include <set>
using namespace std;
typedef pair<int,int> ii;
int n;
int arr[100005];
int p[100005];
int dies[100005];
set<ii> s;
int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
void unions(int i,int j){
    p[i]=j;
}
void print(){
    for (set<ii>::iterator it=s.begin();it!=s.end();it++){
        printf("%d_%d ",(*it).first,(*it).second);
    }
    printf("\n\n");
}
int main(){
    for (int x=0;x<100005;x++){
        p[x]=x;
        dies[x]=-1;
    }
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }
    for (int x=0;x<n;x++){
        while (!s.empty() && (*s.begin()).first<arr[x]) unions((*s.begin()).second,x),s.erase(s.begin());
        while (!s.empty() && (*s.rbegin()).first>(arr[x]<<1)) dies[(*s.rbegin()).second]=x,s.erase(--s.end());
        s.insert(ii(arr[x],x));
    }
    for (int x=0;x<n;x++){
        while (!s.empty() && (*s.begin()).first<arr[x]) unions((*s.begin()).second,x),s.erase(s.begin());
        while (!s.empty() && (*s.rbegin()).first>(arr[x]<<1)) dies[(*s.rbegin()).second]=x,s.erase(--s.end());
        s.insert(ii(arr[x],x));
    }
    for (int x=0;x<n;x++){
        while (!s.empty() && (*s.begin()).first<arr[x]) unions((*s.begin()).second,x),s.erase(s.begin());
        while (!s.empty() && (*s.rbegin()).first>(arr[x]<<1)) dies[(*s.rbegin()).second]=x,s.erase(--s.end());
        s.insert(ii(arr[x],x));
    }
    for (int x=0;x<n;x++){
        if (dies[parent(x)]==-1) printf("-1 ");
        else printf("%d ",(parent(x)-x+n)%n+(dies[parent(x)]-parent(x)+n)%n);
    }
}