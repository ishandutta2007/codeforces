#include<bits/stdc++.h>
using namespace std;
int _,n;

int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        if (n==1){
            puts("-1");
        } else {
            printf("2");
            for (int i=1;i<n;i++) printf("3"); puts("");
        }
    }
    return 0;
}