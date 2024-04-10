#include <cstdio>
#include <cstring>
using namespace std;

const int N = 300;

char text[N + 1];

int out, in;

int main() {
    scanf("%s", text);
    int answer = 0;
    for (int i = 0; text[i]; ++ i) {
        int &from = text[i] == '+' ? out : in;
        int &to = text[i] == '+' ? in : out;
        if (from == 0) {
            answer ++;
            from ++;
        } 
        from --;
        to ++;
    }
    printf("%d\n", answer);
    return 0;
}