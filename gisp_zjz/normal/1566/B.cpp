#include<bits/stdc++.h>
using namespace std;
char s[1223444];
int _,n,k;
int main(){
    cin >> _;
    while (_--){
        scanf("%s",s);
        n=strlen(s);
        k=0;
        for (int i=0;i<n;i++){
            if (s[i]=='1') continue;
            if (i==0||s[i-1]=='1') k++;
        }
        printf("%d\n",min(k,2));
    }
    return 0;
}