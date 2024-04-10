#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        string s,t,tt;
        cin>>s>>t;
        
        sort(s.begin(),s.end());
        for (int x=0;x<=(int)t.size()-(int)s.size();x++){
            tt=t.substr(x,s.size());
            sort(tt.begin(),tt.end());
            if (tt==s) {
                printf("YES\n");
                goto _end;
            }
        }
        printf("NO\n");
        _end:;
    }
}