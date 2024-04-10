#include <stdio.h>
#include <stack>

#define MX 100100

int n,t[MX],p[MX],rank_[MX],best,best_index;

int main() {
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        scanf("%d",&t[i]);
    }

    for(int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        rank_[p[i]]++;
    }

    for(int i=1;i<=n;i++) {

        if(t[i] == 1) {
            int aux = 0, j = i;

            while(1) {
                if(rank_[j] > 1 || j == 0) break;
                //printf("%d\n",j);
                aux++;
                j = p[j];
            }

            if(aux > best) {
                best = aux;
                best_index = i;
            }
        }
    }

    printf("%d\n",best);

        std::stack<int> resp;
        int j = best_index;
        while(j!= 0 && rank_[j] < 2) {
            resp.push(j);
            j = p[j];
        }
        while(!resp.empty()) {
            printf("%d ",resp.top());
            resp.pop();
        }

    return 0;
}