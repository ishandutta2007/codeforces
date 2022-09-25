#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,hn;
int arr[300005];
int pos[300005];
vector<ii> v;
void print(){
    for (int x=1;x<=n;x++){
        printf("%d ",arr[x]);
    }
    printf("\n");
    for (int x=1;x<=n;x++){
        printf("%d ",pos[x]);
    }
    printf("\n\n");
}
void __swap(int i,int j){
    swap(pos[arr[i]],pos[arr[j]]);
    swap(arr[i],arr[j]);
    v.push_back(ii(i,j));
}
void _swap(int i, int j){
    if (j-i>=hn){
        __swap(i,j);
    }
    else if (i<=hn && j<=hn){
        __swap(j,n);
        __swap(i,n);
    }
    else if (i>hn && j>hn){
        __swap(j,1);
        __swap(i,1);
        __swap(j,1);
    }
    else{
        __swap(i,n);
        __swap(1,j);
        __swap(1,n);
        __swap(i,n);
        __swap(1,j);
    }
}
int main(){
    scanf("%d",&n);
    hn=n>>1;
    for (int x=1;x<=n;x++){
        scanf("%d",&arr[x]);
        pos[arr[x]]=x;
    }
    for (int x=1;x<=n;x++){
        if (arr[x]!=x){
            _swap(x,pos[x]);// x<pos[x]
        }
        //print();
    }
    printf("%d\n",v.size());
    for (int x=0;x<(int)v.size();x++){
        printf("%d %d\n",v[x].first,v[x].second);
    }
}