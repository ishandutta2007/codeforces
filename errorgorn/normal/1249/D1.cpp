#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> ii;

long long arr[200005]; //initialize to 0, this is 1-indexed
void update(long long i,long long j){ //adds j to ith term
    while (i<200005){
        arr[i]+=j;
        i+=(i&(-i));
    }
}
long long query(int i){ //calculate the sum of the 0-i terms
    long long k=0;
    while (i>0){
        k+=arr[i];
        i-=(i&(-i));
    }
    return k;
}

int n,k;
struct range{
    int s,e;
    int index;
    range(int a,int b,int c){
        s=a,e=b,index=c;
    }
};
range* val[200005];
vector<int> fin;
priority_queue<ii> pq;
int main(){
    scanf("%d%d",&n,&k);
    int a,b;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        val[x]=new range(a,b,x);
    }
    
    sort(&val[0],&val[n],[](range *i, range *j){
        return i->s<j->s;
    });
    
    for (int x=0;x<n;x++){
        update(val[x]->s,1);
        update(val[x]->e+1,-1);
        pq.push(ii(val[x]->e+1,val[x]->index));
        
        if (query(val[x]->s)>k){
            update(val[x]->s,-1);
            update(pq.top().first,1);
            fin.push_back(pq.top().second);
            pq.pop();
        }
    }
    
    printf("%d\n",fin.size());
    for (int x=0;x<fin.size();x++){
        printf("%d ",fin[x]+1);
    }
}