#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> v;
        set<int> s;
        for(int i = 0;i<2*n;i++){
            int x;
            scanf("%d",&x);
            if(s.find(x)==s.end()){
                v.pb(x);
                s.insert(x);
            }
        }
        for(auto it:v)printf("%d ",it);
        printf("\n");
    }
}