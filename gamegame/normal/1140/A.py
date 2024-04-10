def main():
    n = int(input())
    a = map(int, raw_input().split())
    m = 0
    ans = 0
    for d in range(0,n):
        e=a[d]-1
        if e>m:
	    	m = e
        if d==m:
	    	ans = ans +1
    print(ans)
if __name__ == '__main__':
    main()