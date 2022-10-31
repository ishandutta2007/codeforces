#include <bits/stdc++.h>

#define MN 300300
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int noti[MN], notiread[MN], pos, pos_st[MN];
vector<int> hist;

int main() {
    int n,q,type,x,unread=0,total=0;

    scanf("%d %d",&n ,&q);

    for(int i=0; i<q; i++) {
        scanf("%d %d",&type ,&x);
        if(type == 1) {
            noti[x]++, unread++, total++;
            hist.push_back(x);
        }
        else if(type == 2) {
            unread -= (noti[x] - notiread[x]);
            notiread[x] = noti[x];
        }
        else {
            for(int j=pos; j<x; j++) {
                pos_st[hist[j]]++;

                if(notiread[hist[j]] < pos_st[hist[j]]) {
                    unread--;
                    notiread[hist[j]]++;
                }
            }
            pos = max(pos, x);
        }
        printf("%d\n",unread);
    }
    return 0;
}