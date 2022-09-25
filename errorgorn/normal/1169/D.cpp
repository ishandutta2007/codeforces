#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> v;
int check(int i,int j){
    for (int x=i;x<=j;x++){
        for (int y=x+2;y<=j;y+=2){
            if (v[x]==v[(x+y)>>1] && v[x]==v[y]){
                //printf("%d %d\n",x,y);
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    //freopen("input.txt","r",stdin);
    char c=getchar();
    while (c!='\n'){
        v.push_back(c);
        c=getchar();
    }
    long long ans=(long long)v.size();
    ans=ans*ans+ans;
    ans>>=1;
    //printf("%lld\n",ans);
    for (int x=0;x<v.size();x++){
        for (int y=x;y<min(x+9,(int)v.size());y++){
            //printf("main: %d %d\n",x,y);
            ans-=check(x,y);
        }
    }
    printf("%lld\n",ans);
}