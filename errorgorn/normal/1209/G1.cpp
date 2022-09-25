#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,q;
int first[200005];
int last[200005];
int num[200005];
struct range{
    int first,last,num;
    range(int f, int l, int n){
        first=f;
        last=l;
        num=n;
    }
};
vector<range> ranges;
int main(){
    memset(first,-1,sizeof(first));
    memset(last,-1,sizeof(last));
    scanf("%d%d",&n,&q);
    int k;
    for (int x=0;x<n;x++){
        scanf("%d",&k);
        if (num[k]==0){
            first[k]=x;
            last[k]=x;
            num[k]++;
        }
        else{
            num[k]++;
            last[k]=x;
        }
    }
    for (int x=0;x<200005;x++){
        if (num[x]) ranges.push_back(*new range(first[x],last[x],num[x]));
    }
    sort(ranges.begin(),ranges.end(),[](range &i, range&j){
        return i.first>j.first;
    });
    int last=-1;
    int most=0;
    int curr=0;
    int ans=0;
    while (!ranges.empty()){
        if (ranges.back().first>last){
            ans+=curr-most;
            last=ranges.back().last;
            most=ranges.back().num;
            curr=most;
        }
        else{
            last=max(last,ranges.back().last);
            most=max(most,ranges.back().num);
            curr+=ranges.back().num;
        }
        ranges.pop_back();
    }
    printf("%d\n",ans+curr-most);
}