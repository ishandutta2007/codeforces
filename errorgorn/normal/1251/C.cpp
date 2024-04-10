#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
string s;
queue<int> q[10];
char fin[300005];
int main(){
    int TC;
    scanf("%d",&TC);
    int offset=0;
    int best;
    while (TC--){
        cin>>s;
        offset=0;
        for (int x=0;x<s.size();x++){
            s[x]-='0';
            best=1000000;
            for (int y=s[x]+1;y<10;y+=2){
                if (!q[y].empty()) best=min(best,q[y].front());
            }
            if (best==1000000){
                for (int y=1^(s[x]&1);y<10;y+=2){
                    while (!q[y].empty() && q[y].front()<best){
                        fin[q[y].front()+offset]=y;
                        q[y].pop();
                    }
                }
                q[s[x]].push(x-offset);
            }
            else{
                for (int y=0;y<10;y++){
                    while (!q[y].empty() && q[y].front()<best){
                        fin[q[y].front()+offset]=y;
                        q[y].pop();
                    }
                }
                fin[best+offset]=s[x];
                offset++;
            }
        }
        for (int y=0;y<10;y++){
            while (!q[y].empty()){
                fin[q[y].front()+offset]=y;
                q[y].pop();
            }
        }
        for (int x=0;x<s.size();x++) printf("%c",fin[x]+'0');
        printf("\n");
    }
}