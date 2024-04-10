#include<bits/stdc++.h>
using namespace std;
int main(){
    char c;
    int ans=0;
    for(int i=1;i<=7;i++){
        c=getchar();
        if(c=='A')ans+=1;
        else if(c=='1')ans+=10;
        else ans+=c-'0';
    }
    return printf("%d",ans),0;
}