#include <bits/stdc++.h>
using namespace std;

char s[100005][8];
int t[100005], tn[1000005];
bool isN[100005];
char moves[1000005][2][8];
int n, cur1, lines, cur0, cur0fim, cur1fim, ultimo, inserindo, curtemp, limSuperior;

bool isNumber(char* s) {
    if(s[0] == '0') {
        return false;
    }
    for(int j = 0; j < 6; j++) {
        if(s[j] == '\0') {
            break;
        } else if(s[j] < '0' || s[j] > '9') {
            return false;
        }
    }
    return true;
}

void insertStr(char* s, int j) {
    int cur = (j == 1) ? cur1 : cur0;
    if(j == 1 && cur >= limSuperior) {
        cur = cur1fim;
    } else if(j == 0 && cur > n) {
        cur = cur0fim;
    } 
    while(tn[cur] != -1) {
    	cur++;
        if(j == 1 && cur >= limSuperior) {
            cur = cur1fim;
        } else if(j == 0 && cur > n) {
            cur = cur0fim;
        } 
    }
    strcpy(moves[lines][0], s);
    sprintf (moves[lines++][1], "%d", cur);
    tn[cur] = j;
   	if(j == 1) {
        cur1 = ++cur;
    } else {
        cur0 = ++cur;
    }
}

void insertNum(int i, int j) {
    int cur = (j == 1) ? cur1 : cur0;
    bool futuroUltimo = false, fim = false;
    if(j == 1 && cur >= limSuperior) {
        fim = true;
        cur = cur1fim;
    } else if(j == 0 && cur > n) {
        fim = true;
        cur = cur0fim;
    } 
    while(tn[cur] != -1) {
        if(j == 1) {
            curtemp = cur;
        } 
        if(fim && j == 1 && tn[cur] == 0) {
            inserindo = cur;
            insertNum(cur, 0);
        } else if(fim && j == 0 && tn[cur] == 1) {
            if(inserindo == curtemp) {
                futuroUltimo = true;
                cur++;
            } else {
                insertNum(cur, 1);
            }
        } else {
            cur++;
        }
        
        if(!fim && j == 1 && cur >= limSuperior) {
            fim = true;
            cur1 = cur;
            cur = cur1fim;
        } else if(!fim && j == 0 && cur > n) {
            fim = true;
            cur0 = cur;
            cur = cur0fim;
        } 
    }
    sprintf (moves[lines][0], "%d", i);
    sprintf (moves[lines++][1], "%d", cur);
    tn[i] = -1;
    tn[cur] = j;
    if(futuroUltimo) {
        ultimo = cur;
    } else if(j == 1) {
        if(fim) {
            cur1fim = ++cur;
        } else {
            cur1 = ++cur;
        }
        curtemp = cur;
    } else {
        if(fim) {
            cur0fim = ++cur;
        } else {
            cur0 = ++cur;
        }
    }
}

int main() {
    scanf("%d", &n);
    cur0 = 1;
    lines = 0;
    cur1 = 1;
    ultimo = -1;
    inserindo = -1;
    limSuperior;
    memset(isN, 0, sizeof(isN));
    memset(tn, -1, sizeof(tn));
    for(int i = 0; i < n; i++) {
        scanf("%s %d", s[i], &t[i]);
        if(t[i] == 1) {
            cur0++;
        }
        if(isNumber(s[i])) {
            int atempmeudeus = atoi(s[i]);
            tn[atempmeudeus] = t[i];
            if(atempmeudeus <= n) {
                isN[i] = true;
            }
        }
    }
    limSuperior = cur0;
    cur0fim = cur0;
    cur1fim = cur1;
    for(int i = limSuperior; i <= n; i++) {
        if(tn[i] == 1) {     
        	insertNum(i, tn[i]);
        }
    }
    for(int i = 0; i < limSuperior; i++) {
        if(tn[i] == 0) {     
        	insertNum(i, tn[i]);
        }
    }
    if(ultimo > n) {
        for(int i = limSuperior; i <= n; i++) {
            if(tn[i] == -1) {
                sprintf (moves[lines][0], "%d", ultimo);
                sprintf (moves[lines++][1], "%d", i);
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
    	if(!isN[i]) {
        	insertStr(s[i], t[i]);
        }
    }
    printf("%d\n", lines);
    for(int i = 0; i < lines; i++) {
        printf("move %s %s\n", moves[i][0], moves[i][1]);
    }
    return 0;
}