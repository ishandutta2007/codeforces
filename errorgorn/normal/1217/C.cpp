#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int TC;
    string str;
    vector<ii> old;
    vector<ii> now;
    int bit;
    long long ans=0;
    scanf("%d",&TC);
    int temp;
    while (TC--){
        ans=0;
        cin>>str;
        now.clear();
        now.push_back(ii(0,0));
        for (int _x=0;_x<str.size();_x++){
            old=now;
            now.clear();
            bit=str[_x]-'0';
            for (int x=0;x<old.size();x++){
                now.push_back(ii((old[x].first<<1)+bit,old[x].second));
                if (now.back().first>str.size()) now.pop_back();
            }
            if (now.back().first!=bit){
                now.push_back(ii(bit,_x));
            }
            /*printf("curr vector:\n");
            for (int x=0;x<now.size();x++){
                printf("%d_%d ",now[x].first,now[x].second);
            }
            printf("\n");*/
            now.push_back(ii(-1,_x+1));
            for (int x=0;x<now.size()-1;x++){
                if (now[x].first==0) continue;
                temp=_x-now[x].first+1;
                if (now[x].second<=temp && temp<now[x+1].second) ans++;
            }
            //printf("%d\n",ans);
            now.pop_back();
        }
        printf("%lld\n",ans);
    }
}