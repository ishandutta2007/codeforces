#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main(void){
    int T;
    scanf("%d", &T);
    while(T>0){
        T--;
        m.clear();
        int N;
        scanf("%d", &N);
        int i, a;
        bool c=false;
        for(i=1;i<=N;i++){
            scanf("%d", &a);
            if(m[a]==1)c=true;
            m[a]++;
        }
        if(c){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}