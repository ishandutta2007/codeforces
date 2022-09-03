#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int p[200005];
    for(int i = 1; i < n ; i++){
        scanf("%d",&p[i]);
    }
    int now = 1;
    int Min = 1;
    for(int i = 1 ;i<n;i++){
        now += p[i];
        Min=min(Min,now);
    }
    now =2 - Min;
    vector<int> v;
    v.pb(now);
    //printf("%d",now);
    for(int i = 1;i<n;i++){
        now+=p[i];
        v.pb(now);
        //printf(" %d",now);
    }
    vector<int> temp=v;
    sort(temp.begin(),temp.end());
    for(int i = 0;i<temp.size();i++){
        if(temp[i]!=i+1){
            printf("-1\n");
            return 0;
        }
    }
    for(auto it:v)
    printf("%d ",it);
    printf("\n");
}