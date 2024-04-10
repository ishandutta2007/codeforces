#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

string oleg, igor, res;
int f1[30], f2[30];

void fill_(int pos, string str) {
    int sz = oleg.size() - pos;
    for(int i=pos; i<oleg.size(); i++) {

        int menor = 999, maior = -1, menor2 = 999, maior2 = -1;
        for(int j=0; j<=26; j++) {
            if(f1[j] > 0 && j < menor) menor = j;
            if(f2[j] > 0 && j < menor2) menor2 = j;
            if(f1[j] > 0 && j > maior) maior = j;
            if(f2[j] > 0 && j > maior2) maior2 = j;
        }

        if(i % 2) {
            if(sz % 2) {
                res += ('a' + maior2);
                f2[maior2]--;
            }
            else {
                res += ('a' + menor);
                f1[menor]--;
            }
        }

        else {
            if(sz % 2) {
                res += ('a' + menor);
                f1[menor]--;
            }
            else {
                res += ('a' + maior2);
                f2[maior2]--;
            }
        }
    }
}

int main() {
    cin >> oleg >> igor;

    for(int i=0; i<oleg.size(); i++) {
        f1[oleg[i] - 'a']++;
        f2[igor[i] - 'a']++;
    }

    for(int i=0; i<oleg.size(); i++) {
        if(i % 2) {
            int menor = 999, maior = -1, menor2 = 999, maior2 = -1;
            for(int j=0; j<=26; j++) {
                if(f1[j] > 0 && j < menor) menor = j;
                if(f2[j] > 0 && j < menor2) menor2 = j;
                if(f1[j] > 0 && j > maior) maior = j;
                if(f2[j] > 0 && j > maior2) maior2 = j;
            }

            if(menor < maior2) {
                res += ('a' + maior2);
                f2[maior2]--;
            }

            else {
                fill_(i, res);
                break;
            }
        }
        else {
            int menor = 999, menor2 = 999, maior2 = -1;
            for(int j=0; j<=26; j++) {
                if(f1[j] > 0 && j < menor) menor = j;
                if(f2[j] > 0 && j < menor2) menor2 = j;
                if(f2[j] > 0 && j > maior2) maior2 = j;
            }

            if(menor < maior2) {
                res += ('a' + menor);
                f1[menor]--;
            }

            else {
                fill_(i, res);
                break;
            }
        }
    }

    printf("%s\n", res.c_str());
    return 0;
}

//DSECF