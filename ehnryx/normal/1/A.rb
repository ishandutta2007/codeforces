n, m, a = gets().split().map(&:to_i)
x = n/a + (n % a == 0 ? 0 : 1)
y = m/a + (m % a == 0 ? 0 : 1)
puts x*y