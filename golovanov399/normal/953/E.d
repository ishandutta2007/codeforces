import std.stdio;

/* Hello World Program in D Programming */
void main(string[ ] args)
{
    int n;
    scanf("%d", &n);
    int[211111] a;
    int a_len = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        a[a_len] = a[i];
        ++a_len;
        while (a_len > 1 && a[a_len - 1] == a[a_len - 2]) {
            --a_len;
            ++a[a_len - 1];
        }
    }
    printf("%d\n", a_len);
    for (int i = 0; i < a_len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return;
}