#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main(){
    int TC;
    scanf("%d",&TC);
    bool odd;
    int ones;
    while (TC--){
        odd=false;
        ones=0;
        scanf("%d",&n);
        for (int x=0;x<n;x++){
            cin>>s;
            if (s.size()%2==1) odd=true;
            for (int y=0;y<s.size();y++){
                if (s[y]=='1') ones++;
            }
        }
        if (ones%2==1 && odd==false) printf("%d\n",n-1);
        else printf("%d\n",n);
    }
}