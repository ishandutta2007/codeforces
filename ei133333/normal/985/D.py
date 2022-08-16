N, H = map(int, input().split())

ok = N
ng = 0

while ok - ng > 1:
    mid = (ok + ng) // 2

    if mid <= H:
        sum = mid * (mid + 1) // 2
        if sum < N:
            ng = mid
        else:
            ok = mid
    else:
        sum = H * (H + 1) // 2
        rest = mid - H
        
        sum += rest * H;

        if rest % 2 == 1:
            height = (rest - 1) // 2
            add = height * (height + 1) // 2
            sum += add * 2
        else:
            bottom = rest // 2
            add = bottom * (bottom + 1) // 2
            sum += add * 2
            sum -= bottom
            
        if sum < N:
            ng = mid
        else:
            ok = mid

print(ok)