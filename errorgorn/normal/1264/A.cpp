#include <cstdio>
#include <vector>
using namespace std;
int n;
int arr[400005];
vector<int> v;
int g,s,b;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        v.clear();
        scanf("%d",&n);
        for (int x=0;x<n;x++) scanf("%d",&arr[x]);
        if (n<6){
            printf("0 0 0\n");
            goto _end;
        }
        v.push_back(1);
        for (int x=1;x<(n>>1);x++){
            if (arr[x]==arr[x-1]) v.back()++;
            else v.push_back(1);
        }
        
        if (arr[(n>>1)-1]==arr[(n>>1)]) v.pop_back();
        
        if (v.size()<3){
            printf("0 0 0\n");
            goto _end;
        }
        
        g=v[0];
        s=-v[0],b=0;
        
        for (auto it:v){
            s+=it;
        }
        
        while (v.size()>1){
            b+=v.back();
            s-=v.back();
            v.pop_back();
            if (b>g && s>g){
                printf("%d %d %d\n",g,s,b);
                goto _end;
            }
        }
        
        printf("0 0 0\n");
        _end:;
    }
}