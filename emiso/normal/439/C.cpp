#include <bits/stdc++.h>
#define MN 100010

using namespace std;

int n, k, p, arr[MN], used[MN], odd, even, to, te;
queue<int> qo, qe;

struct num {
    int o, e;

    num operator +(num b) {
        return num {o + b.o, e + b.e};
    }
};

queue<num> no, ne;


int main() {
    scanf("%d %d %d", &n, &k, &p);
    to = k - p, te = p;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] % 2) {
            odd++;
            qo.push(arr[i]);
            no.push(num{1, 0});
        }
        else {
            even++;
            qe.push(arr[i]);
            ne.push(num{0, 1});
        }
    }

    while(odd != to || even != te) {
        if((odd <= to && even <= te) || (odd < to || (odd - to) % 2)) {
            printf("NO\n");
            return 0;
        }

        if(odd > to) {
            odd -= 2;
            even++;

            num o1, o2, o3;
            o1 = no.front(); no.pop();
            o2 = no.front(); no.pop();

            o3 = o1 + o2;
            ne.push(o3);
        }

        else if(even > te) {
            if(ne.size() > 1) {
                num o1, o2, o3;
                o1 = ne.front(); ne.pop();
                o2 = ne.front(); ne.pop();

                o3 = o1 + o2;
                ne.push(o3);
            }

            else if(!no.empty()) {
                num o1, o2, o3;
                o1 = ne.front(); ne.pop();
                o2 = no.front(); no.pop();

                o3 = o1 + o2;
                no.push(o3);
            }

            else {
                printf("NO\n");
                return 0;
            }

            even--;
        }
    }

    printf("YES\n");
    while(!no.empty()) {
        int otp = no.front().o;
        int etp = no.front().e;
        no.pop();

        printf("%d ", otp + etp);
        while(otp--) {printf("%d ", qo.front()); qo.pop();}
        while(etp--) {printf("%d ", qe.front()); qe.pop();}
        puts("");
    }

    while(!ne.empty()) {
        int otp = ne.front().o;
        int etp = ne.front().e;
        ne.pop();

        printf("%d ", otp + etp);
        while(otp--) {printf("%d ", qo.front()); qo.pop();}
        while(etp--) {printf("%d ", qe.front()); qe.pop();}
        puts("");
    }

    return 0;
}