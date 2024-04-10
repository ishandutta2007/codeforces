#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string s;
bool fin[200005];
char first,second;
bool test(int i){
    first='0';
    second='0'+i;
    for (int x=0;x<n;x++){
        if (second<=s[x]){
            fin[x]=true;
            second=s[x];
        }
        else if (first<=s[x]){
            fin[x]=false;
            first=s[x];
        }
        else{
            return false;
        }
    }
    return first<='0'+i;
}
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        cin>>s;
        for (int x=0;x<10;x++){
            if (test(x)){
                for (int x=0;x<n;x++){
                    printf("%d",fin[x]?2:1);
                }
                goto _end;
            }
        }
        printf("-");
        _end:;
        printf("\n");
    }
}