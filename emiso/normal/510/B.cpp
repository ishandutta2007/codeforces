#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int cor[55][55],visit[55][55];
int X[4] = {0,-1,0,1};
int Y[4] = {1,0,-1,0};
int flag = 0;

void bfs(int li, int col) {
    if(visit[li][col] > 0) return;
    visit[li][col] = 1;

    queue <pair<int,int> > fila;
    fila.push(make_pair(li,col));

    while(!fila.empty()) {
        int ali = fila.front().first;
        int acol = fila.front().second;

        for(int i=0;i<4;i++) {
            if(cor[ali][acol] == cor[ali+X[i]][acol+Y[i]]) {
                if(visit[ali+X[i]][acol+Y[i]] == 0) {
                    visit[ali+X[i]][acol+Y[i]] = 1;
                    fila.push(make_pair(ali+X[i],acol+Y[i]));
                }
                else if(visit[ali+X[i]][acol+Y[i]] == 1) {
                    flag = 1;
                }
            }
        }

        visit[ali][acol] = 2;
        fila.pop();
    }
}

int main() {
    int li,col;
    scanf("%d %d ",&li,&col);
    memset(cor,'.',sizeof(cor));
    for(int i=1;i<=li;i++) {
        for(int j=1;j<=col;j++) {
            char c = getchar();
            cor[i][j] = c;
        }
        char c = getchar();
    }

    for(int i=1;i<=li;i++) {
        for(int j=1;j<=col;j++) {
            if(visit[i][j] == 0) bfs(i,j);
        }
    }

    if(flag == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}