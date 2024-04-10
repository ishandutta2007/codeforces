def ask(s):
    print(s)
    ans = int(input())
    if not ans:
        exit(0)
    return ans

def main():
    N = 300
    cnt_a = N - ask('a' * N)
    cnt_b = N - ask('b' * N)
    n = cnt_a + cnt_b
    ans = ['?' for _ in range(n)]
    for i in range(n - 1):
        all_a_mod = 'a' * i + 'b' + 'a' * (n - i - 1)
        if ask(all_a_mod) < cnt_b:
            ans[i] = 'b'
        else:
            ans[i] = 'a'
    if ans.count('a') < cnt_a:
        ans[n - 1] = 'a'
    else:
        ans[n - 1] = 'b'
    ask(''.join(ans))

main()