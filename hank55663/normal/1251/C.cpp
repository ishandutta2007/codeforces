#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define mt make_tuple
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    while(t--){
        vector<int> v1,v2;
        char c[300005];
        scanf("%s",c);
        for(int i = 0;c[i]!=0;i++){
            if((c[i]-'0')&1)v1.pb(c[i]-'0');
            else v2.pb(c[i]-'0');
        }
        v1.pb(1e9),v2.pb(1e9);
        int nowx=0,nowy=0;
        while(nowx!=v1.size()-1||nowy!=v2.size()-1){
            if(v1[nowx]<v2[nowy]){
                printf("%d",v1[nowx++]);
            }
            else
                printf("%d",v2[nowy++]);
        }
        printf("\n");
    }
	return 0;
}