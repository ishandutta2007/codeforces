#include <stdio.h>

int n,k,x,b[110],left,right,ans;

int main() {
    scanf("%d %d %d",&n,&k,&x);
    for(int i=0;i<n;i++) {
        scanf("%d",&b[i]);
    }

    for(int i=1;i<n;i++) {
        if(x == b[i-1] && x == b[i]) {

            left = i-1;
            right = i+1;
            int ret = 2;

            while(1) {
                int flag = 0,aux = 1;

                for(int i = 1; i < n; i++) {
                    int last = b[i-1];
                    if(i == left) {
                        last = b[i-1];
                        i = right;
                    }
                    if(i >= n) break;

                    if(b[i] == last) {
                        aux++;
                    }

                    else {
                        if(aux > 2) {
                            flag = 1;
                            ret += aux;
                            left = i - ret;
                            right = i;
                            aux = 1;
                            break;
                        }

                        aux = 1;
                    }
                }
                if(aux > 2) {
                    flag = 1;
                    ret += aux;
                    left = n -ret;
                    right = n;
                }

                if(!flag) break;
            }

            if(ret > ans) ans = ret;
        }
    }

    printf("%d\n",ans);

    return 0;
}